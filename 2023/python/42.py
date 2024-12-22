with open("../test-cases/inp4.txt", "r") as inpfile:
    cards = inpfile.readlines()
    totalScratchCards = {}
    
    for e in range(1, len(cards)+1):
        totalScratchCards[e] = 1
        
    cNo = totalSC = 0
    for card in cards:
        cNo += 1
        numbers = (card.split(":"))[1].split("|")
        
        winNum = [wnum for wnum in numbers[0].split() if wnum]
        myNum = [mnum for mnum in numbers[1].split() if mnum]
        
        numOfMatch = 0
        for i in range(len(winNum)):
            for j in range(len(myNum)):
                if myNum[j] == winNum[i]:
                    numOfMatch += 1
        
        cnt = totalScratchCards[cNo]
        
        while (cnt>0):
            st = cNo+1
            end = st+numOfMatch
            
            for k in range(st, end):
                totalScratchCards[k]+=1
            
            cnt -= 1
        
    for s in range(1, len(cards)+1):
        totalSC += totalScratchCards[s]
    
    print(f"total scratch cards: {totalSC}")

inpfile.close()