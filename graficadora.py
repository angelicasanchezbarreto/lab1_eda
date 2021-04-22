import matplotlib.pyplot as pyplot
import numpy as np
import pylab as py

#./a.out | python3 graficadora.py
def plot_data(data):
  py.clf()
  py.plot(data)
  py.show()
  py.savefig("dataA.png")

if __name__ == "__main__":
  counter = 0
  while True:
    try:
      tmp = input().strip().split(' ')
      data = np.array(tmp, dtype=np.double)
    except EOFError:
      print ("Input has terminated! Exiting")
      exit()
    except ValueError:
      print ("Invalid input, skipping.  Input was: ",tmp)
      continue
 
    print ("Plotting plot number ", counter)
    plot_data(data)
    counter += 1