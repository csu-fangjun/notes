Basics 1
========

- Creating and combining views

  `<https://developer.apple.com/tutorials/swiftui/creating-and-combining-views>`_

The ``CircleImage.swift`` file::

  //
  //  CircleImage.swift
  //  WhyNotTry
  //
  //  Created by fangjun on 2024/7/25.
  //

  import SwiftUI

  struct CircleImage: View {
      var body: some View {
          Image("turtlerock")
              .clipShape(Circle())
              .overlay {
                  Circle().stroke(.white, lineWidth: 4)
              }
              .shadow(radius: 7)
      }
  }

  struct CircleImage_Previews: PreviewProvider {
      static var previews: some View {
          CircleImage()
      }
  }

The ``ContentView.swfit`` file::

  //
  //  ContentView.swift
  //  WhyNotTry
  //
  //  Created by fangjun on 2024/7/25.
  //

  import SwiftUI

  struct ContentView: View {
      var body: some View {
          VStack {
              CircleImage()

              VStack(alignment: .leading) {
                  Text("Turtle Rock")
                      .font(.title)
                  HStack {
                      Text("Joshua Tree National Park")
                      Spacer()
                      Text("California")
                  }
                  .font(.subheadline)
                  .foregroundStyle(.secondary)

                  Divider()

                  Text("About Turtle Rock")
                      .font(.title2)

                  Text("Descriptive text goes here")

              }
              .padding()

              Spacer()
          }
      }
  }

  struct ContentView_Previews: PreviewProvider {
      static var previews: some View {
          ContentView()
      }
  }

