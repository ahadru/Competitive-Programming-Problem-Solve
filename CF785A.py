
values = {
    'Tetrahedron': 4,
    'Cube': 6,
    'Octahedron': 8,
    'Dodecahedron': 12,
    'Icosahedron': 20
}

n = int(input())

ans = 0
for a in range(0,n):
    ans += values[input()]
print(ans)