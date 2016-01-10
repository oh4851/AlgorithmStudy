__전략__

__기본전략__

- 백트래킹 문제이므로 모든 경우의 수를 확인해 봐야함
- 최대값과 제한값을 비교함
- 이미 방문했던 값은 재방문 하지 않도록 함(중복방지)

- 모든 입력을 받은 후 칼로리의 합(SUM) = 0부터 시작
- SUM이 최대 칼로리(LIMIT)보다 크면 리턴
- SUM이 최대 칼로리보다 작으면서 최대일 경우 MAX에 저장
- VISITED배열을 통해 더한 수를 또 더하지 않도록 만들어줌

__심화전략__

이 문제의 핵심은 `중복이 없는 부분집합의 합을 모두 확인하는 것` 에서 시작

예제

`arr[5] = {7, 9, 13, 17, 19}`

이때, 예상가능한 부분집합: __2^5 = 32__ (0인 경우 제외 -> 31)

```
(7), (9), (13), (17), (19),
(7, 9), (7, 13), (7, 17), (7, 19),
(9, 13), (9, 17), (9, 19),
(13, 17), (13, 19),
...
```

이를 2진수의 비트와, 배열의 인덱스를 매핑시킬 수 있음

- 7 = 10000
- 7, 17 = 10010
- 17, 19 = 00011

이렇게 각 부분집합의 이진수 시퀀스의 1인 인덱스의 값을 합하면 해당 부분집합의 합을 얻을 수 있음

- 7 = 10000
    `(7 * 1) + (9 * 0) + (13 * 0) + (17 * 0) + (19 * 0) = 7`
- 7, 17 = 10010
    `(7 * 1) + (9 * 0) + (13 * 0) + (17 * 1) + (19 * 0) = 24`
- 17, 19 = 00011
    `(7 * 0) + (9 * 0) + (13 * 0) + (17 * 1) + (19 * 1) = 36`