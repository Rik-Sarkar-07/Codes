import cv2
image = cv2.imread("TajMahal.jpg")
print(image)
cv2.imshow('TajMahal Image', image)
cv2.waitKey(0)
