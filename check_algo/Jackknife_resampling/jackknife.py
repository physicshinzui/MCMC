import numpy as np 
import math
import matplotlib.pyplot as plt 

def jackknife(seq):

    # I wanted to determine the number of samples (or width) that each splitted samples has.
    length_of_seq = len(seq)
    if length_of_seq % 2 == 0: 
        dw = 2
    else:
        dw = 3
    
    entire_mean = np.mean(seq)
    print(f'Sequence Length = {length_of_seq}, mean = {entire_mean}')
     
    means, jk_errors = [], []
    for n_samples_for_each in range(2, 1000):
#        print(n_samples_for_each)
        #continue
        splited_seq = np.array_split(seq, n_samples_for_each)

        mean_for_each = list(map(lambda x:np.mean(x), splited_seq))

        jk_error = np.sqrt(np.mean( (mean_for_each - entire_mean)**2) )
        jk_errors.append(jk_error)
        means.append(np.mean(mean_for_each))
        # print(f"Mean for each : {mean_for_each}")
        # print(f"jk error      : {std_w}")

    #return np.array(sorted(means, reverse=True)), np.array(sorted(jk_errors, reverse=True))
    return np.array(means), np.array(jk_errors)

def main():
    arr = np.random.randn(1, 1000000)[0]
    #print(arr)
    #plt.hist(arr, bins=100)
    #plt.show()
    #exit()
    means, jk_errors = jackknife(arr)
#    print(jk_errors)
#    plt.plot()
#    plt.plot(means)
    plt.plot(jk_errors)

    plt.show()
if __name__ == "__main__":
    main()