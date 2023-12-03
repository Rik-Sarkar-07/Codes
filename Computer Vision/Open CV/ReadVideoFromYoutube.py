import pafy  # open anaconda prompt and type pip install pafy
import cv2

url = "https://m.facebook.com/camedulearning/videos/a-teacher-teaches-the-best-life-lesson-to-his-students-________________join-tele/232175852255553/?_rdr"
data = pafy.new(url)
data = data.getbest(preftype="mp4")
cap = cv2.VideoCapture()  # Here parameter 0 is a path of any video use for webcam
cap.open(data.url)
# it is 4 byte code which is use to specify the video codec
fourcc = cv2.VideoWriter_fourcc(*"XVID")  # *"XVID"
# It contain 4 parameter , name, codec,fps,resolution
output = cv2.VideoWriter("FaceBookVideo.avi", fourcc, 20.0, (640, 480), 0)
while cap.isOpened():
    ret, frame = cap.read()  # here read the frame

    if ret:

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        # here flip is used to lip the video at recording time
        # frame = cv2.flip(frame,0)
        # output.write(gray)

        # cv2.imshow("Gray Frame",gray)
        cv2.imshow('Colorframe', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):  # press to exit
            break
    else:
        break

# Release everything if job is finished
cap.release()
output.release()
cv2.destroyAllWindows()
