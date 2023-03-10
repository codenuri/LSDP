// 정리
// 핵심 1. 변하지 않은 코드에서 변하는 것을 분리

// 1. 변하는 것을 가상함수로 해서 파생 클래스가 override
// => template method
// => draw/draw_imp
// 
// 2. 변하는 것을 다른 클래스로 해서, 실행시간 교체 가능
// => 알고리즘의 동적 교체
// => strategy(전략패턴)
// => Edit/IValidator

// 핵심 2. 재귀적 포함 관계
// => A는 B를 포함하지만 A자신도 포함할수 있다.
// => A와 B는 공통의 기반 클래스가 필요

// Composite : 재귀적 포함을 사용한 복합 객체 만들기 = Menu
// Decorator : 재귀적 포함을 사용한 객체의 기능추가 => ZipDecorator



// 핵심 3. 간접층의 도입
// 직접 사용하지 않고, 간접층을 넣는것
// 
// 사용자  ========== stack ================> list
//						// 인터페이스 변경을 위한 어답터
//						// adapter
// 
// client ========== calc  ================> server
//						// 범용적 용도의 대행자
//						// 캐쉬기능, 인증 기능등 추가
//						// proxy

// 핵심 4. 객체를 생성하는 방법 - 내일 많이 등장..
// 1. 아무것도 없는 상태에서 객체를 만들지 말고
//    견본을 먼저 만들고, 복사를 통해서 객체를 생성
//	  => prototype



