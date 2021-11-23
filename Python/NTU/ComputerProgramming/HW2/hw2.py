# some useful python standard libraries
import csv, json, sys
from random import randint
import ipaddress

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
    F = open(json_file, 'r', encoding='UTF-8')
    json_val = json.loads(F.read())
    F.close()

    return json_val

def readQuery(query_file):
    """(10 pt) Return a list of query IPs    
    
    query_file : the directory of query.csv
    
    e.g. ["238.167.63.192", "242.134.236.156", ...]
    
    """
    F = open(query_file, 'r', encoding='UTF-8')
    csv_reader = csv.reader(F)

    IPs = [line[0] for line in csv_reader][1:]
    F.close()

    return IPs    

def writeAns(array, ans_file):
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
    F = open(ans_file, 'w')
    F.write("ip,city\n")
    for IP, city in array:
        F.write(IP + "," + str(city) + "\n")
    F.close()

def sortIP(IPList):
    """(25 pt) Sort the list with each IPs and return the sorted list of dictionary
    
    IPList : the list of dictionary generated with readIPData()
    
    """
    def greater(IP1, IP2):
        IP1 = IP1.split('.')
        IP2 = IP2.split('.')
        for i in range(4):
            if int(IP1[i]) > int(IP2[i]):
                return True
            if int(IP1[i]) < int(IP2[i]):
                return False
        return False

    def merge_sort(lt, rt):
        if rt - lt == 1:
            return

        mid = (lt + rt) // 2
        merge_sort(lt, mid)
        merge_sort(mid, rt)
        
        tmp = []
        p1, p2 = lt, mid
        while p1 < mid or p2 < rt:
            if p1 == mid:
                tmp.append(IPList[p2])
                p2 += 1
            elif p2 == rt:
                tmp.append(IPList[p1])
                p1 += 1
            elif greater(IPList[p1]['ip'], IPList[p2]['ip']):
                tmp.append(IPList[p2])
                p2 += 1
            else:
                tmp.append(IPList[p1])
                p1 += 1

        for i in range(rt - lt):
            IPList[lt + i] = tmp[i]

        return

    merge_sort(0, len(IPList))
    
    return IPList

def binarySearch(array, IP, start, end):
    """(25 pt) perform binary search on a sorted list of dictionaries
    
    return the city of specified IP 
    return -1 if query IP not found
    
    """
    def greater(IP1, IP2):
        IP1 = IP1.split('.')
        IP2 = IP2.split('.')
        for i in range(4):
            if int(IP1[i]) > int(IP2[i]):
                return True
            if int(IP1[i]) < int(IP2[i]):
                return False
        return False

    lt, rt = start, end
    while lt < rt:
        mid = (lt + rt) // 2
        if IP == array[mid]['ip']:
            return array[mid]['city']
        elif greater(IP, array[mid]['ip']):
            lt = mid + 1
        else:
            rt = mid

    return -1

def test_hw2(raw, query, ans):
    """
    combine above works
    (20 pt) if your script complete in 3 seconds 

    """

    db = readIPData(raw)
    query = readQuery(query)
    sortedIP = sortIP(db)
    response = []
    for q in query:
        r = binarySearch(sortedIP, q, 0, len(sortedIP))
        response.append([q, r])
    writeAns(response, ans)

if __name__ == "__main__":
    test_hw2(sys.argv[1], sys.argv[2], sys.argv[3])
