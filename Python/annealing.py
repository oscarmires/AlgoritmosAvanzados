import random

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import math

df = pd.read_csv('annealing_data/cities_128.csv', header=None)


def get_next_temp(temp):
    return temp * 0.995


def cost(city_path):
    distance_sum = 0

    for i in range(len(city_path) - 1):
        a = city_path[i]
        b = city_path[i + 1]
        distance_sum += df[a][b]

    distance_sum += df[len(df) - 1][0]

    return distance_sum


def successor(city_path):
    new_city_path = city_path.copy()

    i = random.randint(0, len(city_path) - 1)
    j = random.randint(i, len(city_path) - 1)
    random.shuffle(new_city_path[i:j])

    return new_city_path


def plot(k_arr, t_arr, cost_arr, city_path):
    # Temperatura
    plt.plot(k_arr, t_arr)
    plt.title("Temperatura")
    plt.ylabel("T")
    plt.xlabel("K")
    plt.show()

    # Costo
    plt.plot(k_arr, cost_arr)
    plt.title("Costo")
    plt.ylabel("Costo")
    plt.xlabel("K")
    plt.show()

    # Ciudades
    plt.title("Ruta óptima")
    plt.ylabel("y")
    plt.xlabel("x")

    coordinates = pd.read_csv('annealing_data/coordinates.csv', header=None)
    cities_x = []
    cities_y = []
    for i in range(len(city_path)):
        cities_x.append(coordinates[0][city_path[i]])
        cities_y.append(coordinates[1][city_path[i]])

    plt.scatter(cities_x, cities_y)
    plt.plot(cities_x, cities_y)
    plt.show()


def simmulated_annealing():
    k = 0

    city_path = np.random.permutation(128)
    e = cost(city_path)
    i_max = 200

    temp = math.ceil(-160000 / math.log(0.7))
    temp_min = 440000

    print("temp inicial: ", temp)
    print("temp min: ", temp_min)

    # plot vars
    k_arr = []
    t_arr = []
    cost_arr = []

    while temp > temp_min:
        for i in range(i_max):
            k += 1

            new_city_path = successor(city_path)
            new_e = cost(new_city_path)
            delta = new_e - e
            if delta > 0:
                if random.random() < math.exp(-delta / temp):
                    city_path = new_city_path
                    e = new_e
            else:
                city_path = new_city_path
                e = new_e

        # save plot values
        k_arr.append(k)
        t_arr.append(temp)
        cost_arr.append(e)

        # update temp
        temp = get_next_temp(temp)

    plot(k_arr, t_arr, cost_arr, city_path)

    # resumen
    print('K: ', k, '| cost: ', cost(city_path), '| T: ', temp)
    print('Path: ', city_path)


simmulated_annealing()
