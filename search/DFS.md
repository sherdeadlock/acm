# DFS Iternative

```
DFS(G, v)
	s = newStack()
	s.push(v)
	while s.isNotEmpty()
		v = s.pop()
		if v.isNotDiscoverd()
			v.discover()
			for edge in G.adjacentEdges
				s.push(edge)
```
