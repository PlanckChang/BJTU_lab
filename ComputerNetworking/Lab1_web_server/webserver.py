
import http.server, os

class ServerException(Exception):
    '''服务器内部错误'''
    pass

class RequestHandler(http.server.BaseHTTPRequestHandler):
    def handle_error(self, msg):
        content = f"{self.path} \r\n {msg}"
        self.send_content(content)

    def send_content(self, content):
        self.send_response(200)
        self.send_header("Content-Type", "text/html")
        self.send_header("Content-Length", str(len(content)))
        self.end_headers()
        self.wfile.write(content.encode("utf-8"))

    def do_GET(self):
        try:
            full_path = os.getcwd() + self.path
            # print(self.path)
            # print(type(self.path))
            if os.path.isfile(full_path):
                # 显示页面
                try:
                    with open(full_path, 'r') as f:
                        content = f.read()
                        # print(content)
                        self.send_content(content)
                except IOError as msg:
                    msg = f"{self.path} cannot be read: {msg}"
                    self.handle_error(msg)
            elif self.path == "/":
                # 显示根页面
                with open("./root.html", 'r') as f:
                    content = f.read()
                    self.send_content(content)
            else:
                # 返回404 不存在此页面
                self.send_error(404, f"{self.path} is not found")
        except Exception as msg:
            self.handle_error(msg)

if __name__ == "__main__":
    serverAddress = ('', 8080)
    server = http.server.HTTPServer(serverAddress, RequestHandler)
    server.serve_forever()
