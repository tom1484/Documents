from scipy.io.wavfile import write
import numpy as np

raw_file = open("raw.txt", "r")
data = np.array([float(r) for r in raw_file.read().split('\n')[:-1]])

data -= np.mean(data)
data /= np.max(np.abs(data))
data *= np.iinfo(np.int16).max

write("out.wav", 10000, data.astype(np.int16))