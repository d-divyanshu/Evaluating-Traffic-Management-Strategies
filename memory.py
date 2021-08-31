import random

class Memory:
    def __init__(self, size_max, size_min):
        self._samples = []
        self._size_max = size_max
        self._size_min = size_min


    def add_sample(self, sample):
        self._samples.append(sample)
        if self._size_now() > self._size_max:
            self._samples.pop(0)


    def get_samples(self, n):
        if self._size_now() < self._size_min:
            return []

        if n > self._size_now():
            return random.sample(self._samples, self._size_now())
        else:
            return random.sample(self._samples, n)


    def _size_now(self):
        return len(self._samples)
