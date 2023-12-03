import cv2 as cv
import numpy as np

img1 = cv.imread("come.jpg", 0)
img2 = cv.imread("go.jpg", 0)

img1 = cv.resize(img1, (1000, 400))
img2 = cv.resize(img2, (1000, 400))

cv.imshow("Coming", img1)
cv.imshow("Going", img2)

imgHor = np.hstack((img1, img2))

imgVar = np.vstack((img1, img2))

cv.imshow("Vertical Merge", imgVar)
cv.imshow("Horizontal Merge", imgHor)



if ord("q"):    # Enter 'q' to Exit
    cv.waitKey()
    cv.destroyAllWindows()
