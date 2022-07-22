import cv2 as cv

vid = cv.VideoCapture("Video.mp4")
# Video is a set of images
while True:
    boolvar, img = vid.read()         # It returns tow fields 1. Boolean value if reading is ok then return true otherwise false || 2. frames
    img = cv.resize(img, (600, 400))  # Resize
    gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
    brgImg = cv.cvtColor(img, cv.COLOR_RGB2BGR)
    cv.imshow('Color Video', img)
    cv.imshow('Gray Video', gray)
    cv.imshow('RGB Video', brgImg)
    if cv.waitKey(25) & 0xFF == ord('q'):       # if enter 'q' then exit 0xFF is a mask value and 25 denotes no ofFrames per mili sec
        break
vid.release()
cv.destroyAllWindows()


# Read  Video From Web Camera

cap = cv.VideoCapture(0)    # 0 denotes primary camera

#it is 4 byte code which is use to specify the video codec
#Various codec --
#DIVX, XVID, MJPG, X264, WMV1, WMV2
fourcc = cv.VideoWriter_fourcc(*"XVID")  # *"XVID"
#It contain 4 parameter , name, codec,fps,resolution
output = cv.VideoWriter("output.avi", fourcc, 20.0, (640, 480), 0)   # 0 -> Gray and 1-> color

while cap.isOpened():
    boolvar, img = cap.read()         # It returns tow fields 1. Boolean value if reading is ok then return true otherwise false || 2. frames
    if boolvar:
        img = cv.resize(img, (600, 400))  # Resize
        gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
        brgImg = cv.cvtColor(img, cv.COLOR_RGB2BGR)
        output.write(brgImg)
        cv.imshow('Color Video', img)
        cv.imshow('Gray Video', gray)
        cv.imshow('RGB Video', brgImg)
        if cv.waitKey(25) & 0xFF == ord('q'):       # if enter 'q' then exit 0xFF is a mask value and 25 denotes no ofFrames per mili sec
            break
cv.destroyAllWindows()
cap.release()
output.release()
