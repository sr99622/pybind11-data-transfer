import cv2
import numpy as np
import sample


img = cv2.imread(cv2.samples.findFile("butterfly.jpg"))

sample.img_in(img)

thing = sample.img_out("lena.jpg")
print(thing.ndim)
print(thing.shape[0])

cv2.imshow("Image OUT", thing)
cv2.waitKey(0)
cv2.destroyAllWindows()

twink = np.asarray(sample.data_out(9, 16))
print(twink.shape)

A = np.array([[0.0, 1.1, 2.2],
              [3.3, 4.4, 5.5],
              [6.6, 7.7, 8.8]])

sample.data_in(A)
