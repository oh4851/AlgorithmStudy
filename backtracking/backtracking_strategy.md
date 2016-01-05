백트래킹 기본 접근 전략

__접근__

- 모든 경우의 수를 보자
- 각 경우의 수마다 기억할 방법을 마련하자
- 컴퓨터로는 어떻게 하지?

__전략__

- 순환(recursive)
- 저장소
- 스택, 큐, 우선순위큐
>> 저장소를 활용하는게 조금 더 빠르다

```
push(StructData(초기값))

while(true)
    SD *now = pop()

    if (now is goal)
        // do something
        return;

    후보군 생성
    for (i=0 ~ 목표값)
        candidate = now.getCandi(i)
        push(candidate)
```
