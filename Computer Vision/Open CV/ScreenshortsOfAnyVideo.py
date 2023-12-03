import cv2 as cv
vidcap = cv.VideoCapture(0)
ret, img = vidcap.read()
count = 0

while True:
    if ret:
        cv.imwrite("A:\\MY PROGGRAMINGS\\pythonProject\\OpenCV\\Example\\f\\imgN%d.jpg" % count, img)  # save frame as JPEG file
        vidcap.set(cv.CAP_PROP_POS_MSEC, (count ** 100))  # used to hold speed of frane generation
        ret, image = vidcap.read()
        cv.imshow("res", image)
        print('Read a new frame:', count, ret)
        count += 1
        if cv.waitKey(1) & 0xFF == ord("q"):
            break
    else:
        break

vidcap.release()
cv.destroyAllWindows()