import cv2 as cv
path = input("Enter The image file name along with location = ")
img = cv.imread(path)

img = cv.cvtColor(img, cv.COLOR_BAYER_RG2GRAY)

cv.imshow("Black & White Image", img)
cv.imwrite("A:\My Files\BSC COMPUTER SCIENCE\image", img)
cv.waitKey()
cv.destroyAllWindows()

