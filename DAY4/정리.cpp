// ������ ������ �ٽ�

// 1. ���뼺�� �������� �и�
/// A. ���ϴ� ���� �����Լ���
///    => tempate method ( draw/draw_imp )
///	   => factory method

/// B. ���ϴ� ���� �ٸ� Ŭ������ (�������̽� ����� ��ü)
///    => strategy ( Edit / IValidator)
///    => state    ( Character / IAction )
///    => builder  ( ������ ��ü�� ���� ������ �ٸ� ǥ������ ����) 
/// 

// 2. �������� ���� ( level of indirection)

/// �����  ======== stack     =======> list
///								adapter : �������̽��� ����
/// 
/// �����  =========TCPServer =======> Socket, IPAddress
///								facade : ����ϱ� ����
/// 
/// �����  =========MP3       ===> IMP3
///								bridge : ������ �߻��� ������ update
/// 
/// �����  =========Calc      ==> IPC����
///								proxy : �پ��� ����� ����
///										�������� ������
/// 

// 23�� ���� - ���� ������ ������

// �������� 5��
// => singleton, prototype, builder, abstract factory, 
//    factory method


// ���� ���� 7��
// => ����� ���� 2�� : composite, decorator
// => �������� ����   : adapter, bridge, facade, proxy
// => ��ü�� ����     : flyweight


// ���� ���� 11��
// => ���ϴ� �� �и� : template method, strategy, state
// => ���ſ� �湮    : iterator, visitor
// => �뺸, ����    : observer, chain of responsiblity
// => ����� ĸ��ȭ(undo) : command
// => ��ü�� ����/����    : memento
// => ��ü���� ���谡 �����ϸ� "������(mediator)"!!

// => �����Ϸ� �ļ����� ���鶧 ��� "iterpreter" ����






