import os
from itertools import chain
import numpy as np
import struct
from PyQt6.QtGui import QImage, QPixmap
from PyQt6.QtWidgets import QApplication, QDialog, QFileDialog, QGraphicsPixmapItem, QGraphicsScene
from grayPictureOP_ui import Ui_gray_picture_op
import sys

class MyHistrgramEqualize(Ui_gray_picture_op, QDialog):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.show()
        self.img = []
        self.open_picture.clicked.connect(self.do_choose_dir)
        self.close_software.clicked.connect(self.close)
        self.equalize.clicked.connect(self.do_equalized_op)
        self.color2gray.clicked.connect(self.do_color2gray)
        self.average_op.clicked.connect(self.do_average)
        self.midium_op.clicked.connect(self.do_middle)


    def do_equalized_op(self):
        self.img_op = histogram_equalization(self.img)
        y = self.img.shape[0]  # 获取图像大小
        x = self.img.shape[1]
        q_img = QImage(self.img_op[:], x, y, x*3, QImage.Format.Format_RGB888)
        # print(1)
        pix = QPixmap.fromImage(q_img)
        item = QGraphicsPixmapItem(pix)
        scene = QGraphicsScene()
        scene.addItem(item)
        self.histogram_equalizied_picture.setScene(scene)

    # 3*3 window
    def do_middle(self):
        self.img_op = np.zeros_like(self.img, dtype=np.uint8)
        tem_img = self.padding_0()

        # height = [i for i in range(1, tem_img.shape[0]-1)]
        # weight = [j for j in range(1, tem_img.shape[1]-1)]

        for i in range(1, tem_img.shape[0] - 1):
            for j in range(1, tem_img.shape[1] - 1):
                mat = tem_img[i-1:i+2, j-1:j+2]
                c = list(chain(*mat))
                sort_list = sorted(c)
                # mat = tem_img[i-1:i+2, ]
                self.img_op[i-1, j-1] = sort_list[4]

        y = self.img.shape[0]  # 获取图像大小
        x = self.img.shape[1]
        q_img = QImage(self.img_op.astype(np.uint8), x, y, x*3, QImage.Format.Format_RGB888)
        # print(1)
        pix = QPixmap.fromImage(q_img)
        item = QGraphicsPixmapItem(pix)
        scene = QGraphicsScene()
        scene.addItem(item)
        self.histogram_equalizied_picture.setScene(scene)


    def do_average(self):
        # def fun1(j):
        #     global i
        #     mat = tem_img[i - 1:i + 2, j - 1:j + 2]
        #     mean = np.sum(mat) / 9
        #     self.img_op[i - 1, j - 1] = mean

        tem_img = self.padding_0()
        self.img_op = np.zeros_like(self.img, dtype=np.uint8)
        
        for i in range(1, tem_img.shape[0] - 1):
            for j in range(1, tem_img.shape[1] - 1):
            # map(fun1, [j for j in range(1, tem_img.shape[1]-1)])

                mat = tem_img[i-1:i+2, j-1:j+2]
                mean = np.sum(mat) / 9
                self.img_op[i-1, j-1] = mean

        y = self.img.shape[0]  # 获取图像大小
        x = self.img.shape[1]
        q_img = QImage(self.img_op.astype(np.uint8), x, y, x*3, QImage.Format.Format_RGB888)
        # print(1)
        pix = QPixmap.fromImage(q_img)
        item = QGraphicsPixmapItem(pix)
        scene = QGraphicsScene()
        scene.addItem(item)
        self.histogram_equalizied_picture.setScene(scene)



    def padding_0(self):
        tem_ = np.zeros(shape=(self.img.shape[0]+2, self.img.shape[1]+2), dtype=np.uint8)
        tem_[1:tem_.shape[0]-1, 1:tem_.shape[1]-1] = self.img[:,:,0]
        return tem_

    def do_color2gray(self):
        r = self.img[:, :, 0]
        g = self.img[:, :, 1]
        b = self.img[:, :, 2]
        self.img[:, :, 0] = 0.11 * r + 0.59*g + 0.3 * b
        self.img[:, :, 1] = self.img[:, :, 0]
        self.img[:, :, 2] = self.img[:, :, 0]
        q_img = QImage(self.img[:], self.img.shape[1], self.img.shape[0], self.img.shape[1]*3, QImage.Format.Format_RGB888)

        pix = QPixmap.fromImage(q_img)
        item = QGraphicsPixmapItem(pix)
        scene = QGraphicsScene()
        scene.addItem(item)
        self.source_picture.setScene(scene)


    def do_choose_dir(self):
        file_name, _ = QFileDialog.getOpenFileName(self, "请选择要打开的bmp图像", os.getcwd(), "*.bmp")

        self.img = open_picture(file_name)
        y = self.img.shape[0]  # 获取图像大小
        x = self.img.shape[1]

        # img = cv2.imread(r"tiger.bmp")
        # img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        # print(self.img == img)
        # print(type(img))
        # print("seperate line")
        # print(type(self.img))
        # q_img = QImage(img, x, y, x*3, QImage.Format.Format_RGB888)

        q_img = QImage(self.img[:], x, y, x*3, QImage.Format.Format_RGB888)
        # print(1)
        pix = QPixmap.fromImage(q_img)
        item = QGraphicsPixmapItem(pix)
        scene = QGraphicsScene()
        scene.addItem(item)
        self.source_picture.setScene(scene)

def open_picture(file_path):
    """
    return shape numpy [height, width, channel]
    """

    img = []
    f = open(file_path, 'rb')
    # 打开对应的文件

    # '下面部分用来读取BMP位图的基础信息'
    f_type = str(f.read(2))  # 这个就可以用来读取 文件类型 需要读取2个字节
    file_size_byte = f.read(4)  # 这个可以用来读取文件的大小 需要读取4个字节
    f.seek(f.tell() + 4)  # 跳过中间无用的四个字节
    file_offset_byte = f.read(4)  # 读取位图数据的偏移量

    f.seek(f.tell() + 4)  # 跳过无用的四个字节
    file_wide_byte = f.read(4)  # 读取宽度字节
    file_height_byte = f.read(4)  # 读取高度字节
    f.seek(f.tell() + 2)  # 跳过中间无用的两个字节 颜色板
    file_bitcount_byte = f.read(4)  # 得到每个像素占位大小

    # 下面就是将读取的字节转换成指定的类型
    f_size, = struct.unpack('l', file_size_byte)
    f_offset, = struct.unpack('l', file_offset_byte)
    f_wide, = struct.unpack('l', file_wide_byte)
    f_height, = struct.unpack('l', file_height_byte)
    f_bit_count, = struct.unpack('i', file_bitcount_byte)
    print("类型:", f_type, "大小:", f_size, "位图数据偏移量:", f_offset, "宽度:", f_wide, "高度:", f_height, "位图:", f_bit_count)

    '然后来读取颜色表'
    color_table = np.empty(shape=[256, 3], dtype=int)
    f.seek(54)  # 跳过文件信息头和位图信息头

    if f_bit_count == 8:
        for i in range(0, 256):
            # B G R Alpha per 1B
            b = struct.unpack('B', f.read(1))[0]
            g = struct.unpack('B', f.read(1))[0]
            r = struct.unpack('B', f.read(1))[0]
            alpha = struct.unpack('B', f.read(1))[0]
            color_table[i][0] = r
            color_table[i][1] = g
            color_table[i][2] = b
            # color_table[i][3] = 255
    # '下面部分用来读取BMP位图数据区域,将数据存入numpy数组'
    # 首先对文件指针进行偏移
    f.seek(f_offset)
    # 因为图像是8位伪彩色图像，所以一个像素点占一个字节，即8位
    # 按Bit count来读取每一个像素的值

    if f_bit_count == 8:
        img = np.empty(shape=[f_height, f_wide, 3], dtype=int)
        count = 0
        for y in range(0, f_height):
            for x in range(0, f_wide):
                count = count + 1
                index = struct.unpack('B', f.read(1))
                # print(index)
                img[f_height - y - 1, x] = color_table[index]
            while count % 4 != 0:
                f.read(1)
                count = count + 1
    elif f_bit_count == 24:
        img = np.empty(shape=[f_height, f_wide, 3], dtype=int)
        count = 0
        for y in range(0, f_height):
            for x in range(0, f_wide):
                count = count + 1
                b = struct.unpack('B', f.read(1))
                g = struct.unpack('B', f.read(1))
                r = struct.unpack('B', f.read(1))
                # 倒着读 顺着写
                img[f_height - y - 1, x][0:3] = np.array([r, g, b]).reshape((3,))
            while count % 4 != 0:
                f.read(3)
                count = count + 1

    f.close()
    return img.astype(np.uint8)



def histogram_equalization(img):
    img_tem = img.copy()
    tab = np.zeros(256)
    count = np.bincount(img_tem[:,:,0].flatten())
    tab[0:count.shape[0]] = count
    tab = tab.cumsum()
    tab = (tab / tab[-1]  * 256).astype(np.uint8)
    # print(tab.shape)
    # tab = tab.reshape((img.shape))
    print(type(img_tem.shape))

    for x in range(img_tem.shape[0]):
        for y in range(img_tem.shape[1]):
            img_tem[x, y, 0:3] = tab[img_tem[x, y, 0]]
    return img_tem.astype(np.uint8)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    my_histogram_equalize = MyHistrgramEqualize()
    sys.exit(app.exec())









