import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns

plt.rcParams.update({'font.size': 20})
fig_size = (19.2, 12)


def make_plot(title, data):
    path = "./plotting/"

    plt.figure(figsize=fig_size, constrained_layout=True)
    sns.set_style("darkgrid")

    for i, col in enumerate(data.columns[1:]):
        sns.lineplot(x="bit_sz", y=col, data=data, label=col)

    plt.title(title)
    plt.ylabel('miliseconds')
    plt.xlabel('Public key bit size')
    if title == "time_test":
        plt.xticks(data["bit_sz"])
    else:
        plt.xlim(60, 100)
        plt.xticks(np.arange(60, 101, 4))
    plt.savefig(path + title + ".png")


def get_data(path, cols):
    data = []
    with open(path, "r") as file:
        while True:
            try:
                bit_sz = int(file.readline().split()[1])
            except (EOFError, IndexError):
                break
            for t in range(10):
                li = [int(i) for i in file.readline().split()]
                data.append([bit_sz] + li)
    return pd.DataFrame(data, columns=["bit_sz"] + cols)


if __name__ == "__main__":
    cols = ["Key Generation", "Encription", "Decription", "Key Break"]
    data = get_data("time_testing/time_break_log.txt", cols)
    make_plot("time_break", data)
    data = get_data("time_testing/time_test_log.txt", cols[:-1])
    make_plot("time_test", data)
