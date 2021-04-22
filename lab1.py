from sklearn.neighbors import NearestNeighbors
import csv
import numpy as np
import random
from time import time
import graficadora

def read_file(filename):
    with open(filename) as file:
        csv_reader = csv.reader(file, delimiter=',')
        row1 = []
        row2 = []
        num_rows = 0;
        for row in csv_reader:
            if num_rows == 0:
                row1 = row
                num_rows+=1
            else:
                row2 = row
    return fill_array(row1,row2)

def fill_array(row1,row2):
    points = []
    for num in range(0, len(row1)):
        points.append([int(row1[num]),int(row2[num])])
    return points

def knn(points,k):
    nbrs = NearestNeighbors(n_neighbors=k, algorithm='kd_tree').fit(points)
    p_base = random.choice(points)
    distances, indices = nbrs.kneighbors([p_base])
    """ for i in range(0,k):
        print(points[indices[0][i]]) """
        
def get_times(points,num_experiments,k):
    times = []
    for i in range(0,num_experiments):
        startTime = time()
        knn(points,k)
        elapsedTime = time() - startTime
        times.append(elapsedTime*1000)
    with open('times2.txt', 'w') as f:
        for item in times:
            f.write("%s\n" % item)


pointsA = read_file("dsA.csv")
pointsB = read_file("dsB.csv")
pointsC = read_file("dsC.csv")
get_times(pointsC,5000,5)
