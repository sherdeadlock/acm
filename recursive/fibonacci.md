# Recursive

1 1 2 3 5 8 13 ...

```
fibonacci(n)
	if n == 0 or n == 1 return i
	return fibonacci(i - 1) + fibonacci(i - 2)
```


# Top-Down DynamicProgramming
```
memo[0] = memo[1] = 1
fibonacci(n, memo)
	if n == 0 or n == 1 return i
	if memo[i] == 0
		memo[i] = fibonacci(i - 1, memo) + fibonacci(i - 2, memo)
	return memo[i]
```
