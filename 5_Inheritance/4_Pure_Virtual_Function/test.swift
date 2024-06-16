import Foundation

final class Animal { 
  let height: Int

  init() { 
    self.height = 1
  }

  // func speak() { 
  //   print("animal!")
  // }
}

// class Cat: Animal { 
//   private let weight: Int

//   override init() { 
//     self.weight = 1
//   }

//   override func speak() {
//     print("Cat!")
//   }
// }

func sizeOfInstance<T>(_ type: T.Type) -> Int {
    return class_getInstanceSize(type as! AnyClass)
}

do { 
  let a = Animal()
  // let c = Cat()
  print(class_getInstanceSize(Animal.self)) 
  // print(class_getInstanceSize(Cat.self)) 
}