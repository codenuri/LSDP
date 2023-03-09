// 디자인 패턴의 핵심

// 1. 공통성과 가변성의 분리
/// A. 변하는 것을 가상함수로
///    => tempate method ( draw/draw_imp )
///	   => factory method

/// B. 변하는 것을 다른 클래스로 (인터페이스 기반의 교체)
///    => strategy ( Edit / IValidator)
///    => state    ( Character / IAction )
///    => builder  ( 복잡한 객체를 동일 공정의 다른 표현으로 생성) 
/// 

// 2. 간접층의 도입 ( level of indirection)

/// 사용자  ======== stack     =======> list
///								adapter : 인터페이스의 변경
/// 
/// 사용자  =========TCPServer =======> Socket, IPAddress
///								facade : 사용하기 쉽게
/// 
/// 사용자  =========MP3       ===> IMP3
///								bridge : 구현과 추상의 독립적 update
/// 
/// 사용자  =========Calc      ==> IPC서버
///								proxy : 다양한 기능을 위한
///										범용적인 대행자
/// 

// 23개 패턴 - 교재 마지막 페이지

// 생성패턴 5개
// => singleton, prototype, builder, abstract factory, 
//    factory method


// 구조 패턴 7개
// => 재귀적 포함 2개 : composite, decorator
// => 간접층을 도입   : adapter, bridge, facade, proxy
// => 객체의 공유     : flyweight


// 행위 패턴 11개
// => 변하는 것 분리 : template method, strategy, state
// => 열거와 방문    : iterator, visitor
// => 통보, 전달    : observer, chain of responsiblity
// => 명령의 캡슐화(undo) : command
// => 객체의 저장/복구    : memento
// => 객체간의 관계가 복잡하면 "중재자(mediator)"!!

// => 컴파일러 파서등을 만들때 사용 "iterpreter" 패턴






