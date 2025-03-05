import time

t0 = time.time()

seq = [1, 2, 2]
pointer = 1
next_value = 2
while len(seq) < 1000000000:
    # Calculam care este urmatoarea valoare de adaugat
    next_value = 3 - next_value

    # Calculam cate elemente de tipul next_value trebuie adaugate
    count = seq[pointer]

    # Adaugam elementele in secventa
    for i in range(count):
        seq.append(next_value)
    
    # Mutam pointerul la urmatorul element
    pointer = pointer + 1

t1 = time.time()
print("Time: ", t1 - t0)