# some useful python standard libraries
import csv, json, sys
from random import randint
import ipaddress
import os

def readIPData(json_file):
    """(10 pt) Return the a list of dictionary of raw data
    
    json_file : the directory of db.json
    
    e.g. [{
            "ip":"238.167.63.192",
            "city": "Denison"
          },
          {
            "ip": "242.134.236.156",
            "city": "Hackensack"
          },
          ...
            ]
    """
    jsolist = open(json_file,'r')
    return json.loads(jsolist.read())

def readQuery(query_file):
    """(10 pt) Return a list of query IPs    
    
    query_file : the directory of query.csv
    
    e.g. ["238.167.63.192", "242.134.236.156", ...]
    
    """
    queryy = open(query_file, "r")
    csvread = csv.reader(queryy)
    csv2 = []
    for i in csvread:
        csv2.append(i[0])
    return csv2[1:]


def writeAns(array, ans_file):
    import os
    """(10 pt) Write query answer to csv file
    
    array : response answer of each query 
    ans_file : output file directory
    
    output csv should be in this format:
    
    ip,city
    238.167.63.192,Denison
    242.134.236.156,Hackensack
    8.8.8.8,-1
    ...
    
    """
    with open(ans_file, 'w') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerows(array)


def sortIP(IPList):
    """(25 pt) Sort the list with each IPs and return the sorted list of dictionary
    
    IPList : the list of dictionary generated with readIPData()
    
    """

    def sortrecurtion(a, b):
        if a+1 == b :
            return
        m =  (a+b)//2
        sortrecurtion(a, m)
        sortrecurtion(m, b)
        n = []
        i,j = a, m
        while i != m or j != b:
            if i == m:
                n.extend(IPList[j:b])
                j = b
            elif j == b:
                n.extend(IPList[i:m])
                i = m
            elif IPList[i]['ip'] > IPList[j]['ip']:
                n.append(IPList[j])
                j += 1
            else :
                n.append(IPList[i])
                i += 1
        for i in range(a,b):
            IPList[i] = n[i - a]
    sortrecurtion(0, len(IPList))
    return IPList
        

def binarySearch(array, IP, start, end):
    """(25 pt) perform binary search on a sorted list of dictionaries
    
    return the city of specified IP 
    return -1 if query IP not found
    
    """
    a, b = start, end
    finalIP = -1
    while b - a > 1:
        m = (a + b)//2
        if array[a]['ip'] > IP or array[b - 1]['ip'] <= IP :
            b = a + 1
            break
        else:
            if array[m]['ip'] < IP :
                a = m
            elif array[m]['ip'] > IP :
                b = m
            elif array[m]['ip'] == IP :
                finalIP = array[m]['city']
                b = a + 1
    return finalIP

def test_hw2(raw, query, ans):
    """
    combine above works
    (20 pt) if your script complete in 3 seconds 

    """
    db = readIPData(raw)
    query = readQuery(query)
    # print(query)
    
    sortedIP = sortIP(db)
    print(sortedIP)
    response = []
    for q in query:
        r = binarySearch(sortedIP, q, 0, len(sortedIP))
        response.append([q, r])
    writeAns(response, ans)

if __name__ == "__main__":
    test_hw2(sys.argv[1], sys.argv[2], sys.argv[3])

