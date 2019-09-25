//BFS的两个主要使用场景：遍历+找出最短路径

//返回root和target之间的最短路径：
/*
模板1：
*/
int BFS(Node root, Node target){
	Queue<Node> queue; //保存待处理的所有节点
	int step = 0; //从root到current所需步数
	//初始化
	add root to queue;
	//BFS
	while(queue is not empty){
		step = step + 1;
		//迭代已经在queue中节点
		int size = queue.size();
		for(int i=0;i<size;i++){
			Node cur = the first node in queue;
			return step if cur is target;
			for(Node next : the neighbors of cur){
				add next to queue;
			}
			remove the first node from queue;
		}
	}
	return -1; //没有从root到target的路径
}
//1.队列中的结点时等待处理的结点
//2.在每个外层的while循环结束以后，我们距离根结点更远一步，step记录这一距离。

/*
模板二：
使用哈希集保证不会访问一个结点两次
*/
int BFS(Node root, Node target){
	Queue<Node> queue;
	Set<Node> used;	//保存使用的结点
	int step = 0;
	//初始化
	add root to queue;
	add root to used;
	//BFS
	while(queue is not empty){
		step = step+1;
		//迭代已经在queue中的结点
		int size = queue.size()
		for(int i=0;i<size;i++){
			Node cur = the first node in queue;
			return step if cur is target;
			for(Node next:the neighbors of cur){
				if(next is not in used){
					add next to queue;
					add next to used;
				}
			}
			remove the first node from queue;
		}
	}
	return -1; //没有从root到target的路径
}
//无需使用模板二的两种情况：
//1.确定完全没有循环，如在树的遍历中
//2.确实希望多次将结点添加到队列中