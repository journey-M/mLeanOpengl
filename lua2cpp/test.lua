local abc = require("testlib")
 
avg,sum = abc.average(100, 200, 300, 400, 500)
 
diff = abc.sub(100,50)
total = abc.add(100,50)
 
print("Average is:" ..avg)
print("Sum is: " ..sum)
 
print("diff = "..diff)
print("total = "..total)
