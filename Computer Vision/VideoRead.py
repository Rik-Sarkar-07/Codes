import cv2
capture = cv2.VideoCapture('Wildlife.wmv')

while True:
     isTrue, frame = capture.read()
     cv2.imshow('Video Play', frame)

     if cv2.waitKey(20) & 0xFF == ord('p'):
         break

capture.release()
cv2.destroyWindow()
