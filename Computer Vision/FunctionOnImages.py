import cv2 as cv
import numpy as np

kernel = np.ones((5, 5), np.uint8)
img = cv.imread("TajMahal.jpg")
imgGray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
imgBlur = cv.GaussianBlur(imgGray, (7, 7), 0)
imgCanny = cv.Canny(img, 150, 200)
imgDialation = cv.dilate(imgCanny, kernel, iterations=2)
imgEroded = cv.erode(imgDialation, kernel, iterations=2)

cv.imshow("Real Image", img)
cv.imshow("Gray Image", imgGray)
cv.imshow("Blur Image", imgBlur)
cv.imshow("Canny Image", imgCanny)
cv.imshow("Dialated Image", imgDialation)
cv.imshow("Eroded Image", imgEroded)

if ord("q"):    # Enter 'q' to Exit
    cv.waitKey()
    cv.destroyAllWindows()
