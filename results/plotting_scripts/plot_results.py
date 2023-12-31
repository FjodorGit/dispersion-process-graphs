import numpy as np
import pandas as pd
import re
import os

# This script produces the tables for the mean and variance of the distribution

# compute mean and variance from dat files in distribution data folders
data_dir_name = "/home/fjk/Uni/Bachelorarbeit/graph-dispersion/results/distribution/fully_connected/capacity_1/data"

particle_count = []
graph_size = []
mean = []
variance = []
for file in os.listdir(data_dir_name):
    if file.endswith(".dat"):
        [n, M] = re.findall(r"\d+", file)
        graph_size.append(n)
        particle_count.append(M)
        with open(data_dir_name + "/" + file, "r") as file:
            array = np.array([float(line.strip()) for line in file.readlines()], dtype=float)
            mean.append(np.mean(array))
            variance.append(np.var(array))

data_dict = {"Graph Size": graph_size, "Particle count": particle_count, "Sample Mean": mean, "Sample Variance": variance}
data_df = pd.DataFrame.from_dict(data_dict)

output_file = "/home/fjk/Uni/Bachelorarbeit/Arbeit/bilder/distribution_cap1/mv_table.tex"
with open(output_file, "w+") as result_file:
    data_df.to_latex(buf = result_file, index=False)

# same procedure for capacity 2
data_dir_name = "/home/fjk/Uni/Bachelorarbeit/graph-dispersion/results/distribution/fully_connected/capacity_2/data"

particle_count = []
graph_size = []
mean = []
variance = []
for file in os.listdir(data_dir_name):
    if file.endswith(".dat"):
        [n, M] = re.findall(r"\d+", file)
        graph_size.append(n)
        particle_count.append(M)
        with open(data_dir_name + "/" + file, "r") as file:
            array = np.array([float(line.strip()) for line in file.readlines()], dtype=float)
            mean.append(np.mean(array))
            variance.append(np.var(array))

data_dict = {"Graph Size": graph_size, "Particle count": particle_count, "Sample Mean": mean, "Sample Variance": variance}
data_df = pd.DataFrame.from_dict(data_dict)

output_file = "/home/fjk/Uni/Bachelorarbeit/Arbeit/bilder/distribution_cap1/mv_table_cap2.tex"
with open(output_file, "w+") as result_file:
    data_df.to_latex(buf = result_file, index=False)
    
