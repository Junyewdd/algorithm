import sys

N = int(sys.stdin.readline().strip())
tree = {}

for n in range(N):
    root, left, right = sys.stdin.readline().strip().split(' ')
    tree[root] = [left, right]
    
def preorder(root):
    #root left right
    if root != '.':
        print(root, end='')
        preorder(tree[root][0])
        preorder(tree[root][1])
    

def inorder(root):
    #left root right
    if root != '.':
        inorder(tree[root][0])
        print(root, end='')
        inorder(tree[root][1])
    
def postorder(root):
    #left right root
    if root != '.':
        postorder(tree[root][0])
        postorder(tree[root][1])
        print(root, end='')
        
preorder('A')
print()
inorder('A')
print()
postorder('A')