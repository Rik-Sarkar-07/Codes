import cv2 as cv
img1 = cv.imread('TajMahal.jpg', 1)      # Normal Color Image
img2 = cv.imread('TajMahal.jpg', 0)     # Read as a Gray image
img3 = cv.imread('TajMahal.jpg', -1)    # Read as an Unchanged image (including alpha channel)

img = cv.resize(img2, (200, 100))       # Resize Along with Width & Hight

cv.imshow('Real Image', img1)
cv.imshow('Gray from of the Image', img2)
cv.imshow('Unchanged Image', img3)
cv.imshow('Resize from of the Image', img)
cv.waitKey()                            # it takes parameret as mili sec as dealay of closing
cv.destroyAllWindows()

im = cv.flip(img1, 1)                   # it accept 3 parameters 0,-1,1 (Like as a mirror)
cv.imshow('Mirror Image', im)
# Save The Mirror Image
k = cv.waitKey() & 0xFF
if k == ord('q'):                        # Enter 'q' to exit
    cv.destroyAllWindows()
elif k == ord('s'):                      # Enter 's' to save
    cv.imwrite('A:\\My Files\\BSC COMPUTER SCIENCE\\Mirror.png', im)
    cv.destroyAllWindows()


