header = "P3\n511 511\n255\n";

fd = open("image.ppm", "w");
fd.write(header);

body = "";
gradient = 0;
for y in range(0, 511):
    for x in range(0, 511):
        ygrad = abs(255-y);
        xgrad = abs(255-x);
        gradient = (ygrad + xgrad)/2;
        #gradient = ygrad;
        #if xgrad > ygrad:
        #    gradient = xgrad;
        #if(ygrad > 170 and xgrad > 170):
        if(gradient > 170):
            body += "255 255 "
            body += str(gradient) + " "
        #elif(ygrad >80 and ygrad > 80):
        elif(gradient > 90):
            body += "255 "
            body += str(gradient)
            body += " 255 "
        else:
            body += str(gradient);
            body += " 255 255 "
        #body += str(gradient);
        #body += " 255 255 "

fd.write(body)
fd.close()
