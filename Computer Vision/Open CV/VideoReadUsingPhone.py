import cv2 as cv
camera = "http://25.196.163.197:8080/video"
# connet divice via same net work using IP Webcam
cap = cv.VideoCapture(0)
cap.open(camera)    # Open Camera
#it is 4 byte code which is use to specify the video codec
fourcc = cv.VideoWriter_fourcc(*"XVID")  # *"XVID"
#It contain 4 parameter , name, codec,fps,resolution
output = cv.VideoWriter("MobileCam.avi", fourcc, 30.0, (640, 480), 0)
#20.0 fps, (680,480) resuluation , 0 gray video

while cap.isOpened():
    ret, frame = cap.read()  # here read the frame
    if ret:

        frame = cv.resize(frame, (700, 700))
        gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
        cv.imshow("Gray Frame", gray)
        cv.imshow('Colorframe', frame)
        if cv.waitKey(1) & 0xFF == ord('q'):  # press to exit
            break

# Release everything if job is finished
cap.release()
output.release()
cv.destroyAllWindows()
