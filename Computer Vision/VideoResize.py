import cv2
capture = cv2.VideoCapture('Wildlife.wmv')
def ResizeFunction(frame,scale=0.75):
    width = int(frame.shape[1]*scale)
    height = int(frame.shape[0]*scale)
    dimensions = (width,height)
    return cv2.resize(frame,dimensions, interpolation=cv2.INTER_AREA)
while True:
     isTrue, frame = capture.read()
     cv2.imshow('Video Play', frame)
     frameResize = ResizeFunction(frame)
     cv2.imshow('Resize Video', frameResize)
     if cv2.waitKey(20) & 0xFF == ord('p'):
         break
capture.release()
cv2.destroyWindow()
