1) read all tetraminos to list
    - deside wich thingth i need to store in list

    - i need to find first left-upper point and choose it as main
        ((find(#))
    - for each 4 lines i need to place  tetramino  to upper left side
         (i can use defined buff just replacing to right position)
2) realize backtracking algorythm
    - function place() which will place next tetramino to l-u corner
       if ( (buid-in function to check() is tetramino fits in))
        write() #funtion write letters
        place() #recursive move on next tetramino
        else
        move to right and try again
        else
        upper size of area and start again


i can use coordinats
i can use findchr/strlen and count4
same for writing to area
in check(i need try to fit every point of tetramino to position)