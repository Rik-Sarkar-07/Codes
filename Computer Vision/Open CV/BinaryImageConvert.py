import cv2 as cv
img = cv.imread("TajMahal.jpg")
imgGray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow("Color Image", img)
cv.imshow("Gray Image", imgGray)
ret, ImgBin = cv.threshold(imgGray, 180, 220, cv.THRESH_BINARY)
cv.imshow("Binary Image", ImgBin)
if ord("q"):
    cv.waitKey()
    cv.destroyAllWindows()