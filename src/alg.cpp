// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int pairs = 0;

  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        pairs++;
    }
  }

  return pairs;
}

int countPairs2(int *arr, int len, int value) {
  int pairs = 0;
  int s = 0;
  int e = len - 1;

  while (s < e - 1) {
    int c = (e + s) / 2;

    if (arr[c] <= value) {
      s = c + 1;
    } else {
      e = c;
    }
  }

  for (int i = 0; i < e; i++) {
    for (int j = e; j > i; j--) {
      int sum = arr[i] + arr[j];
      if (sum == value) {
        pairs++;
      } else if (sum < value) {
        break;
      } else {
        continue;
      }
    }
  }

  return pairs;
}

int countPairs3(int *arr, int len, int value) {
    int pairs = 0;
    int s = 0;
    int e = len - 1;

    while (s < e - 1) {
      int center = (s + e) / 2;

      if (arr[center] <= value) {
        s = center;
      } else {
        e = center;
      }
    }

    int l = e - 1;

    for (int i = 0; i < l; i++) {
      s = i + 1;
      e = l - 1;

      while (s < e) {
        int center = (s + e) / 2;

        if (arr[center] < (value - arr[i])) {
          s = center + 1;
        } else {
          e = center;
        }
      }

      while (arr[s] == (value - arr[i])) {
        pairs++;
        s++;
      }
    }

    return pairs;
}
