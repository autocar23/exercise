struct X
{
	//���󣬳�ʼ���б��ʼ��˳��Ϊ��Ա��������˳�򣬸ò���Ϊδ�����
	X (int i, int j):base(i), rem(base % j){ } 
	//��ȷ��ʽ
	X(int i, int j) :base(i), rem(i % j) { }
	int rem, base;
};