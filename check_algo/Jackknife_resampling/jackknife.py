import numpy as np 
import math

def jackknife(seq):

    # I wanted to determine the number of samples (or width) that each splitted samples has.
    length_of_seq = len(seq)
    if length_of_seq % 2 == 0: 
        dw = 2
    else:
        dw = 3
    
    entire_mean = np.array(seq)

    # 
    for n_samples_for_each in range(0, 10, dw):
        splited_seq = np.split(seq, n_samples_for_each)

        mean_for_each = list(map(lambda x:np.mean(x), splited_seq)) 
        std_w = np.std(mean_for_each)
        print(f"Mean for each : {mean_for_each}")
        print(f"jk error      : {std_w}")

    return 0 #jackknife_errors


def main():
    arr = np.random.randn(1, 10)[0]
    print(arr)
    jackknife(arr)

if __name__ == "__main__":
    main()