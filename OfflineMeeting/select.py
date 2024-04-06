import random

# 1부터 6까지의 숫자 리스트 생성
numbers = [1, 2, 3, 4, 5, 6]

# 랜덤으로 3개 선택
random_selection = random.sample(numbers, 3)

print("선택된 숫자:", random_selection)
