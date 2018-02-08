# DFS Iternative

```
DFS(v)
	s = newStack()
	s.push(v)
	while s.isNotEmpty()
		v = s.pop()
		if v.isNotDiscoverd()
			v.discover()
			for edge in v.adjacentEdges
				s.push(edge)
```
