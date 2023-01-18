
import cv2
import numpy as np

def cascade():
    global nose_cascade
    global eyes_cascade
    global mouth_cascade
    nose_cascade = cv2.CascadeClassifier("haarcascade_mcs_nose.xml")
    nose_cascade.load("./haarcascade_mcs_nose.xml")  # 文件所在的具体位置
    '''此文件是opencv的haar鼻子特征分类器'''
    eyes_cascade = cv2.CascadeClassifier("haarcascade_eye_tree_eyeglasses.xml")
    eyes_cascade.load("./haarcascade_eye_tree_eyeglasses.xml")  # 文件所在的具体位置
    # eyes_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + "haarcascade_eye.xml")
    # eyes_cascade.load("./haarcascade_eye_2.xml")  # 文件所在的具体位置

    mouth_cascade = cv2.CascadeClassifier("haarcascade_mcs_mouth.xml")
    mouth_cascade.load("./haarcascade_mcs_mouth.xml")


def nose_dection(gray):
    """实现鼻子检测"""
    # img = cv2.GaussianBlur(img ,(5 ,5) ,0 )  # 高斯滤波
    # gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)                     # 将图片转化成灰度
    # nose_cascade = cv2.CascadeClassifier("haarcascade_mcs_nose.xml")
    # nose_cascade.load("./haarcascade_mcs_nose.xml")  # 文件所在的具体位置
    noses = nose_cascade.detectMultiScale(gray, 1.3, 5)  # 鼻子检测
    # for(x ,y ,w ,h) in noses:
    #     cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)  # 画框标识鼻子
    flag = 0            # 检测到鼻子的标志位，如果监测到鼻子，则判断未带口罩
    if len(noses ) >0:
        flag = 1
    return flag, noses


def eye_dection(gray):
    """"实现眼睛检测"""

    '''此文件是opencv的haar眼睛特征分类器'''
    eyes = eyes_cascade.detectMultiScale(gray, 1.3, 5)
    return len(eyes), eyes

def empty(a):
    pass

def mouth_detection(gray):
    """to detect mouth """
    # mouth_cascade = cv2.CascadeClassifier(",.xml")
    # mouth_cascade.load("./haarcascade_mcs_mouth.xml")
    mouth = mouth_cascade.detectMultiScale(gray, 1.3, 5)
    if len(mouth):
        return 1, mouth
    else:
        return 0, mouth


def position_mask(eyes, shape):
    # 口罩区域的提取
    mask_x_begin = min(eyes[0][0], eyes[1][0])  # 把左眼的x坐标作为口罩区域起始x坐标
    mask_x_end = max(eyes[0][0], eyes[1][0]) + eyes[list([eyes[0][0], eyes[1][0]]).index(max(list([eyes[0][0], eyes[1][0]])))][2]
    # 把右眼x坐标 + 右眼宽度作为口罩区域x的终止坐标
    mask_y_begin = max(eyes[0][1] + eyes[0][3], eyes[1][1] + eyes[1][3])
    mask_y_begin = int(mask_y_begin+5)

    if mask_y_begin > shape[1]:  # 判断是否出界
        mask_y_begin = shape[1]
    mask_y_end = max(eyes[0][1] + 2.75 * eyes[0][3], eyes[1][1] + 2.75 * eyes[1][3])  # 同理
    mask_y_end = int(mask_y_end+5)
    if mask_y_end > shape[1]:
        mask_y_end = shape[1]

    # print("x ", mask_x_begin, mask_x_end)
    # print("y", mask_y_begin, mask_y_end)
    return mask_x_begin, mask_x_end, mask_y_begin, mask_y_end


def main(mouth_mode = True):
    cascade()
    capture = cv2.VideoCapture(0)
    _, image = capture.read()      # 读取背景照片
    cv2.imshow('skin', image)                       # 展示
    cv2.createTrackbar("Hmin", "skin", 0, 90, empty)    # 创建bar
    cv2.createTrackbar("Hmax", "skin", 25, 90, empty)

    while True:
        ref ,img =capture.read()                  # 打开摄像头

        img = cv2.GaussianBlur(img, (5, 5), 0)  # 高斯滤波
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        flag_nose, position_nose = nose_dection(gray)       # 进行口罩检测，返回检测之后的图形以及标志位

        if flag_nose == 1:              # 当检测到鼻子的时候，判断未戴口罩
            cv2.putText(img, "NO MASK", (10, 30), cv2.FONT_HERSHEY_COMPLEX, 0.9 ,(0, 0, 255), 1)  # 在图片上写字
            for(x ,y ,w ,h) in position_nose:
                cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)  # 画框标识鼻子
            cv2.imshow('img', img)       # 展示图片
        elif flag_nose == 0:              # 未检测鼻子，进行眼睛检测
            flag_eye, position_eyes = eye_dection(gray)         # 进行眼睛检测，返回检测之后的图形以及标志位
            hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)        # 将图片转化成HSV格式
            H, S, V = cv2.split(hsv)                          #
            Hmin= cv2.getTrackbarPos("Hmin", 'skin')           # 获取bar
            Hmax= cv2.getTrackbarPos("Hmax", 'skin')
            if Hmin> Hmax:
                Hmax= Hmin
            thresh_h = cv2.inRange(H, Hmin, Hmax)       # 提取人体肤色区域
            if flag_eye > 1:                           # 判断是否检测到两个眼睛，其中eyes[0]为左眼坐标
                # 口罩区域的提取
                for (x, y, w, h) in position_eyes:
                    cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)  # 画框标识眼睛

                mask_x_begin, mask_x_end, mask_y_begin, mask_y_end = position_mask(position_eyes, img.shape)

                cv2.rectangle(img, (mask_x_begin, mask_y_begin), (mask_x_end, mask_y_end), (255, 0, 0), 2)
                # 向量化
                total_mask_pixel = np.sum(thresh_h[mask_x_begin:mask_x_end, mask_y_begin:mask_y_end] == 0)
                total_face_pixel = (mask_x_end - mask_x_begin) *(mask_y_end-mask_y_begin) - total_mask_pixel
                # debug
                print(thresh_h[mask_x_begin:mask_x_end, mask_y_begin:mask_y_end])
                print("total_mask_pixel" ,total_mask_pixel)
                print("total_face_pixel", total_face_pixel)
                if mouth_mode == True:
                    flag_mouth, position_mouth = mouth_detection(gray)
                else:
                    flag_mouth = 0
                    position_mouth = [0, 0, 0, 0]
                if total_mask_pixel > total_face_pixel and flag_mouth == 0:
                    cv2.putText(img, "HAVE MASK", (mask_x_begin, mask_y_begin - 10), cv2.FONT_HERSHEY_COMPLEX, 0.9, (0, 0, 255), 1)  # 绘制
                elif flag_mouth == 1:
                    cv2.putText(img, "NO MASK", (mask_x_begin, mask_y_begin - 10), cv2.FONT_HERSHEY_COMPLEX, 0.9, (0, 0, 255), 1)  # 绘制
                    for x, y, w, h in position_mouth:
                        cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)  # 画框标识嘴巴
            cv2.imshow("skin", thresh_h)  # 显示肤色图
            cv2.imshow("img", img)  # 显示肤色图

        c = cv2.waitKey(10)

        if c == 27:
            break

    capture.release()  #
    cv2.destroyAllWindows()  # 关闭所有窗口


if __name__ == '__main__':
    main(mouth_mode= False)