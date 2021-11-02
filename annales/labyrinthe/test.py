
import sys

if(len(sys.argv) < 3):
    print('missing arguments')
    exit(1)

found = open(sys.argv[2], 'r')
expected = open(sys.argv[1], 'r')

if found is None:
    print('unable to open '+argv[2])
    exit(2)
    
if expected is None:
    print('unable to open '+argv[1])
    exit(3)

position = [int (x) for x in expected.readline().split()]
for l in found:
    c = int(l.split()[1])
    if c < 2:
        position[c]-=1
    elif c < 4:
        position[c-2]+=1
    else:
        print("wrong door")
        exit(5)

if position == [0, 0]:
    exit(0)
    
exit(6)