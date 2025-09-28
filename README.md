# COS214-Project-Repo
## Hallo all :smirk:
Welcome to our FINAL PROJECT for 214 :confetti_ball:

***Below are some action points that we should clarify before jumping in. Everything mentioned is purely a suggestion and a foundation to build on. The floor is open for discussion and debate, this just gives us something concrete to work off of***

Guidelines and rules for consistency (big brother will be watching you :expressionless:)
- Meetings
  - Weekly meetings from the week of 29-09-2025 to end of project before tutor check-ins
  - Review progress, address pain points early, discuss upcoming tasks
  - Meeting notes/project planning
    - Some options:
      - Custom notion board, can link notion with github, easy for notes + planner + team colab. We have access to pro version via @tuks accounts.
      - GitHub Projects, bit more limited but can seemlessly link issues directly to the repo
      - Non-inclusive list, any ideas welcome    
- Deadlines as per the specification
  - 28 Sept: Register team, assign leader.
  - 6 Oct: Submit Practical 5 (initial design + diagrams).
  - 20 Oct: Skeleton implementation ready.
  - 27 Oct: Working version + demo prep.
  - 2 Nov: Final submission (report, diagrams, code).
  - 3–5 Nov: Demo sessions
- Communication
  - WhatsApp group and Discord Server + whatever collab approach we are going to use (Notion, GitHub projects)
    - Discord server GitHub bot which relays everything happening on the repo (feel free to mute this channel, will be getting a lot of notifications)
  - Transparency is mandatory. If you are struggling with something and predict that you might not finish on time, please do not be afraid to mention it. We are all in the same boat and understand how hectic/difficult things can get. If issues regarding internal deadlines are raised early we can redistribute the load and reduce pressure placed on an individual team member. We are in this together.
  - Be mindful when changing unreviewed code that is not your own. Communicate what you are doing and why with the author of the code until that code is approved and the feature merged to limit conflicts.
- Branching strategy
  - 2 Main branches
    - main
      - Reserved for features that are fully working, tested and integrated  
    - dev
      - Reserved for completed and tested features, integration pending
  - Feature branches
    - Branch created for each feature, always branching off dev
    - e.g. `observer-attach`  
- Review PRs
  - At least 1 preferrably 2 reviewers per PR.
- Visual Paradigm
  - Visual paradigm online provides all of the features available on the native app, just a terrible UX. The advantage of using VP Online is real time collaboration. Coordinating `.vpp` files between 5 members would be terrible. With VP online, all changes made to a diagram is immediately visible to all members, i.e. if you decide to add a function to a class that you are working on that change would be visible to all as soon as you update the diagram, eliminating the pain of having to manually merge diagrams.  
- GitHub Actions (Gerard can set up github actions, Megan is really good with making code pretty she has made a linter/formatter previously so can reuse that)
  - Linter
  - Merge Tester (When a branch is merged into dev, linter will be applied for formatting and static bug checks and some automated testing. If one of these actions fail, it will not be possible to merge the branch until the appropriate changes are made such that the tests run successfully)
- Testing
  - Preferably [GoogleTest](https://google.github.io/googletest/)
