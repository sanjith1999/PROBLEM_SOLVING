#check for even
def even(x):
    if len(x[0])%2==0 and len(x[1]%2)==0:
        return True
    return False


# Seperating links
def seperate_links(links):
    Seperated=[]
    for link in links:
        # Handling no elements in Seperation
        if not(Seperated):
            Seperated.append(link.copy())
        else:
            #appending elements in seperated lists according to need
            for i,seperation in enumerate(Seperated):
                # if first element of link in seperated list handle it according to the second element
                if link[0] in seperation:
                    if link[1] in seperation:
                        break;

                    else:
                        #seperating out the remaining list other than the considered one.
                        remains=Seperated[:i]+Seperated[i+1:]
                        for remain in remains:
                            if link[1] in remain:
                                Seperated[i]+=remain
                                Seperated.remove(remain)
                                break;
                        else:
                            Seperated[i].append(link[1])
                    break;
                      
            else:
                for i,seperation in enumerate(Seperated):
                    if link[1] in seperation:
                        Seperated[i].append(link[0])
                        break;
                else:
                    Seperated.append(link.copy())
    return Seperated


#solution
def Solution(links):
    P=0
    Q=0
    for m in range(len(links)):
        r_links=links[:m]+links[m+1:]
        x=seperate_links(r_links)
        if len(x)==2:
            if even(x):
                P+=1
            else:
                Q+=1
      
    if not(P):
        if not(Q):
            return '0 0'
        return '0 1'
    if not(Q):
        return '1 0'
    for i in range(2,min(int(P**0.5),int(Q**0.5))):
        if P%i==0 and Q%i==0:
            P/=i 
            Q/=i      
    return str(P)+' '+str(Q)


print(Solution([[1,2],[2,3],[3,1],[4,5],[5,6],[6,4]]))