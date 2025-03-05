import time
import sys
sys.setrecursionlimit(1000000000)

t0 = time.time()

def generate_kolakoski(seq, pointer, next_value, target_length):
    if len(seq) > target_length:
        return seq[:target_length]
    
    # Alternăm între 1 și 2
    next_val = 3 - next_value  
    
    # Numărul de repetări este dat de elementul curent din secvență
    count = seq[pointer]
    
    # Extindem secvența cu next_val repetat de 'count' ori
    seq.extend([next_val] * count)
    
    # Recurăm cu pointerul incrementat
    return generate_kolakoski(seq, pointer + 1, next_val, target_length)

seq = [1, 2, 2]

# Lungimea secvenței
target_length = 1000000000

sequence = generate_kolakoski(seq, 2, 2, target_length)

t1 = time.time()
print("Time: ", t1 - t0)