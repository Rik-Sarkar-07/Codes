import cv2
image = cv2.imread("Rahda krishna.jpg")
cv2.imshow('Real Image', image)
# Create a Resize Function
def ResizeFunction(frame,scale=0.75):
    width = int(frame.shape[1]*scale)
    height = int(frame.shape[0]*scale)
    dimensions = (width,height)
    return cv2.resize(frame,dimensions, interpolation=cv2.INTER_AREA)
# Call The Function
resizeimage = ResizeFunction(image,scale=0.4)
cv2.imshow('ReSize image', resizeimage)
cv2.waitKey(0)
