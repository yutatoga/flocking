# flocking 01
![flocking 01](https://farm2.staticflickr.com/1472/25954391520_f7c145910b_o_d.gif)  
Mac OS 10.11.3（15D21）  
XCode Version 7.3 (7D175)  
Addons: [ofxFlock](https://github.com/mummey/ofxFlock "ofxFlock") ([29597fab3d15cd3897b65b69190026222b372abf](https://github.com/mummey/ofxFlock/commit/29597fab3d15cd3897b65b69190026222b372abf))  
 Change src>CBoid.h like below  
 ```
 #include "ofVectorMath.h"
-#include "flockApp.h"
+#define MAX_BOIDS   30
+#define MAX_FLOCKS  5
```
