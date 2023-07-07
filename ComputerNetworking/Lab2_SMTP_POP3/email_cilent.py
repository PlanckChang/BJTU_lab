import email.parser
import smtplib
from email.mime.text import MIMEText
from email.header import Header
from poplib import POP3
from email.parser import Parser
from email.header import decode_header
from email.utils import parseaddr


def send_mail(title, message):
    # 三个参数：第一个为文本内容，第二个 plain 设置文本格式，第三个 utf-8 设置编码
    message = MIMEText(message, 'plain', 'utf-8')
    message['From'] = Header(sender, 'utf-8')  # 发送者
    message['To'] = Header(*receivers, 'utf-8')  # 接收者
    message['Subject'] = Header(title, 'utf-8')

    smtpObj = smtplib.SMTP_SSL(mail_host, 465)
    smtpObj.login(mail_user, mail_pass)
    smtpObj.sendmail(sender, receivers, message.as_string())


def print_info(msg, indent=0):
    if indent == 0:
        for header in ['From', 'To', 'Subject']:
            value = msg.get(header, '')
            if value:
                if header == 'Subject':
                    value = decode_str(value)
                else:
                    hdr, addr = parseaddr(value)
                    name = decode_str(hdr)
                    value = u'%s <%s>' % (name, addr)
            print('%s%s: %s' % ('  ' * indent, header, value))
    #   process the body
    if msg.is_multipart():
        parts = msg.get_payload()
        for n, part in enumerate(parts):
            print('%spart %s' % ('  ' * indent, n))
            print('%s--------------------' % ('  ' * indent))
            print_info(part, indent + 1)
    else:
        content_type = msg.get_content_type()
        if content_type == 'text/plain' or content_type == 'text/html':
            content = msg.get_payload(decode=True)
            charset = guess_charset(msg)
            if charset:
                content = content.decode(charset)
            print('%sText: %s' % ('  ' * indent, content + '...'))
        else:
            print('%sAttachment: %s' % ('  ' * indent, content_type))


def decode_str(s):
    value, charset = decode_header(s)[0]
    if charset:
        value = value.decode(charset)
    return value


def guess_charset(msg):
    # auto capture the charset
    charset = msg.get_charset()
    # manually capture by retrieving "Content-Type"
    if charset is None:
        content_type = msg.get('Content-Type', '').lower()
        pos = content_type.find('charset=')
        if pos >= 0:
            charset = content_type[pos + 8:].strip()
    return charset


if __name__ == "__main__":
    mail_host = "mail.bjtu.edu.cn"  # 设置服务器
    mail_user = "20271259"  # 用户名
    mail_pass = "YQjJKdiAkCDKEVCm"  # 密码、授权码

    sender = '20271259@bjtu.edu.cn'  # 发送邮箱
    receivers = ['20271235@bjtu.edu.cn']  # 接收邮箱

    server = POP3(mail_host)
    server.user(mail_user)
    server.pass_(mail_pass)

    # send_mail('【测试】邮件发送测试', 'for test')

    print("welcome", mail_user)
    print("following are your mails in", mail_host)
    print("==="*20)
    emailNum, size = server.stat()
    print("Messages: %s. size: %s" % (emailNum, size))  # 返回邮箱的数量和占用空间
    resp, mails, octets = server.list()  # 返回所有邮箱的编号
    if len(mails) >=10:
        print("the prior 10 mails num if below")
        print(* (mails[:10]))
    else:
        print(*mails)
    print("===" * 20)

    print("for test, we default show the latest mail")
    index = len(mails)

    resp, lines, octets = server.retr(index)
    # return a MIMEMultipart class
    msg_content = b'\r\n'.join(lines).decode('utf-8')  # 每一行加入换行,并转化为UTF-8类型
    msg = Parser().parsestr(msg_content)
    print_info(msg)

    server.quit()
