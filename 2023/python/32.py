with open("../test-cases/inp3.txt", "r") as inpfile:
    lines = inpfile.readlines()
    sumofgearatio = 0
    
    def checkforgears(start, end, line, gears):
        for j in range(max(0, start), min(end, len(line))):
                if line[j:j+3].isdigit():
                    num = line[j:j+3]
                elif line[j:j+2].isdigit() and not line[j-1].isdigit():
                    num = line[j:j+2]
                elif line[j].isdigit() and not line[j-1].isdigit():
                    num = line[j]
                else:
                    continue
                
                gears.append(int(num))
    
    for i in range(len(lines)):
        pL = lines[i-1] if i-1 >= 0 else ""
        mL = lines[i]
        nL = lines[i+1] if i+1 < len(lines) else ""
        
        for j in range(len(mL)):
            gears = []
            if mL[j] == "*":
                x = j
                if pL[x-1].isdigit():
                    checkforgears(x-3, x+2, pL, gears)
                elif pL[x].isdigit() or pL[x+1].isdigit():
                    checkforgears(x, x+2, pL, gears)
                
                if mL[x-1].isdigit():
                    checkforgears(x-3, x+2, mL, gears)
                elif mL[x+1].isdigit():
                    checkforgears(x+1, x+2, mL, gears)
                
                if nL[x-1].isdigit():
                    checkforgears(x-3, x+2, nL, gears)
                elif nL[x].isdigit() or nL[x+1].isdigit():
                    checkforgears(x, x+2, nL, gears)
                
            else:
                continue
            
            if len(gears) == 2:
                sumofgearatio += gears[0]*gears[1]
            else:
                continue
                  

print(f"Sum of gear ratios: {sumofgearatio}")
inpfile.close()  