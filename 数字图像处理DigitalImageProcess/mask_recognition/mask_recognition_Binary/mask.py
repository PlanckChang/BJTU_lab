
import cv2
import numpy as np
from func_timeout import func_set_timeout
import func_timeout

def cascade():
    global nose_cascade
    global eyes_cascade
    global mouth_cascade
    nose_cascade = cv2.CascadeClassifier("haarcascade_mcs_nose.xml")
    nose_cascade.load("./haarcascade_mcs_nose.xml")  # 文件所在的具体位置
    '''此文件是opencv的haar鼻子特征分类器'''
    eyes_cascade = cv2.CascadeClassifier("haarcascade_eye_tree_eyeglasses.xml")
    eyes_cascade.load("./haarcascade_eye_tree_eyeglasses.xml")  # 文件所在的具体位置
    mouth_cascade = cv2.CascadeClassifier("haarcascade_mcs_mouth.xml")
    mouth_cascade.load("./haarcascade_mcs_mouth.xml")

timeout_ = 1
@func_set_timeout(timeout_)
def nose_dection(gray):
    """实现鼻子检测"""
    print("noses")
    noses = nose_cascade.detectMultiScale(gray, 1.3, 5)  # 鼻子检测
    flag = 0
    if len(noses) > 0:
        flag = 1
    return flag, noses

@func_set_timeout(timeout_)
def eye_dection(gray):
    """"实现眼睛检测"""
    # eyes_cascade = cv2.CascadeClassifier("haarcascade_mcs_eyepair_small.xml")
    # eyes_cascade.load("./haarcascade_mcs_eyepair_small.xml")  # 文件所在的具体位置
    '''此文件是opencv的haar眼睛特征分类器'''
    print("eyes")
    eyes = eyes_cascade.detectMultiScale(gray, 1.3, 5)          # 眼睛检测
    return len(eyes), eyes

@func_set_timeout(timeout_)
def mouth_detection(gray):
    """to detect mouth """
    mouth = mouth_cascade.detectMultiScale(gray, 1.3, 5)

    if len(mouth):
        return 1, mouth
    else:
        return 0, mouth


def empty(a):
    pass


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


def mask_color(binary):
    print("mask color")
    many = np.sum(binary==0)
    less = np.sum(binary==255)
    if many > less:
        many = 255
        less = 0
    else:
        many = 0
        less = 255
    return many, less


def main(image=None, mouth=True):
    cascade()
    capture = cv2.VideoCapture(0)  # 打开摄像头，其中0为自带摄像头，

    # background = "./background.png" # 读取背景照片
    # background = cv2.imread(background)
    # cv2.imshow('skin', background)                       # 展示
    #
    # cv2.createTrackbar("Hmin", "skin", 0, 90, empty)    # 创建bar
    # cv2.createTrackbar("Hmax", "skin", 25, 90, empty)

    while True:
        if image is None:
            ref, img = capture.read()
            img = cv2.flip(img, 1)
        else:
            img = image

        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        # _, thresh_h = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
        thresh_h = gray
        cv2.imshow("skin", thresh_h)  # 显示肤色图
        cv2.imshow("img", img)

        try:
            flag_nose, position_nose = nose_dection(gray)
        except func_timeout.exceptions.FunctionTimedOut:
            print("nose timeout")
            continue
        if mouth:
            try:
                flag_mouth, position_mouth = mouth_detection(gray)
            except func_timeout.exceptions.FunctionTimedOut:
                print("mouth timeout")
                continue
        else:
            flag_mouth = 0
            position_mouth = None

        if flag_nose == 1 or flag_mouth == 1:  # 当检测到鼻子 或 嘴巴的时候，判断未戴口罩
            cv2.putText(img, "NO MASK", (10, 30), cv2.FONT_HERSHEY_COMPLEX, 0.9, (0, 0, 255), 1)  # 在图片上写字
            for (x, y, w, h) in position_nose:
                cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)  # 画框标识鼻子
            if position_mouth is not None:
                for (x, y, w, h) in position_mouth:
                    cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)  # 画框标识嘴巴
            print("No Mask")
            cv2.imshow("skin", thresh_h)  # 显示肤色图
            cv2.imshow("img", img)
        else:
            try:
                flag_eye, eyes = eye_dection(gray)
            except func_timeout.exceptions.FunctionTimedOut:
                print("eye timeout")
                continue

            if flag_eye > 1:
                many, less = mask_color(thresh_h)
                mask_x_begin, mask_x_end, mask_y_begin, mask_y_end =  position_mask(eyes, img.shape)

                cv2.rectangle(img, (mask_x_begin, mask_y_begin), (mask_x_end, mask_y_end), (255, 0, 0), 2)  # 画口罩区域的框
                for (x, y, w, h) in eyes:
                    cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)  # 画框标识眼部

                # 遍历二值图，为0则total_mask_pixel+1，否则total_face_pixel, 修改为向量化计算 加快速度
                total_mask_pixel = np.sum(thresh_h[mask_x_begin:mask_x_end, mask_y_begin:mask_y_end] == many)
                total_face_pixel = np.sum(thresh_h[mask_x_begin:mask_x_end, mask_y_begin:mask_y_end] == less)
                # print(thresh_h[mask_x_begin:mask_x_end, mask_y_begin:mask_y_end])

                # print(mask_x_begin)
                # print(mask_x_end)
                # print(mask_y_begin)
                # print(mask_y_end)
                print("total_mask_pixel" ,total_mask_pixel)
                print("total_face_pixel", total_face_pixel)
                if total_mask_pixel > total_face_pixel:
                    cv2.putText(img, "HAVE MASK", (mask_x_begin, mask_y_begin - 10), cv2.FONT_HERSHEY_COMPLEX, 0.9, (0, 0, 255), 1)  # 绘制
                    print("Have Mask")

                cv2.imshow("skin", thresh_h)  # 显示肤色图
                cv2.imshow("img", img)

        if cv2.waitKey(10) == 27:
            break

    capture.release()  #
    cv2.destroyAllWindows()  # 关闭所有窗口

if __name__ == '__main__':
    no_mask_path = "./test_no_mask.jpg"
    # mask_path = "./test_with_mask.jpg"
    mask_path = "./new_mask_data/51.jpg"
    img_no = cv2.imread(no_mask_path)
    img_mask = cv2.imread(mask_path)
    # main(img_mask, mouth=False)
    main(mouth=False)