(window.webpackJsonp=window.webpackJsonp||[]).push([[3],{ttZb:function(t,e,r){"use strict";r.d(e,"a",(function(){return j})),r.d(e,"b",(function(){return g})),r.d(e,"c",(function(){return v})),r.d(e,"d",(function(){return d})),r.d(e,"e",(function(){return h})),r.d(e,"f",(function(){return y}));var i=r("lqOT"),s=r("mrSG"),n=r("q1tI"),o=r.n(n),u=r("dMq0"),a=r("qx2n"),c=r("qVdT"),p=function(){function t(t,e){this.isMounted=!1,this.previousOptions={},this.context={},this.options={},this.options=t||{},this.context=e||{}}return t.prototype.getOptions=function(){return this.options},t.prototype.setOptions=function(t,e){void 0===e&&(e=!1),e&&!Object(a.a)(this.options,t)&&(this.previousOptions=this.options),this.options=t},t.prototype.unmount=function(){this.isMounted=!1},t.prototype.refreshClient=function(){var t=this.options&&this.options.client||this.context&&this.context.client;Object(c.b)(!!t,2);var e=!1;return t!==this.client&&(e=!0,this.client=t,this.cleanup()),{client:this.client,isNew:e}},t.prototype.verifyDocumentType=function(t,e){var r=Object(i.f)(t);Object(i.e)(e),Object(i.e)(r.type);Object(c.b)(r.type===e,3)},t}(),l=function(t){function e(e){var r=e.options,i=e.context,s=e.forceUpdate,n=t.call(this,r,i)||this;return n.previousData={},n.currentObservable={},n.runLazy=!1,n.runLazyQuery=function(t){n.cleanup(),n.runLazy=!0,n.lazyOptions=t,n.forceUpdate()},n.getExecuteResult=function(){var t=n.getQueryResult();return n.startQuerySubscription(),t},n.obsRefetch=function(t){return n.currentObservable.query.refetch(t)},n.obsFetchMore=function(t){return n.currentObservable.query.fetchMore(t)},n.obsUpdateQuery=function(t){return n.currentObservable.query.updateQuery(t)},n.obsStartPolling=function(t){n.currentObservable&&n.currentObservable.query&&n.currentObservable.query.startPolling(t)},n.obsStopPolling=function(){n.currentObservable&&n.currentObservable.query&&n.currentObservable.query.stopPolling()},n.obsSubscribeToMore=function(t){return n.currentObservable.query.subscribeToMore(t)},n.forceUpdate=s,n}return Object(s.c)(e,t),e.prototype.execute=function(){this.refreshClient();var t=this.getOptions(),e=t.skip,r=t.query;return(e||r!==this.previousData.query)&&(this.removeQuerySubscription(),this.previousData.query=r),this.updateObservableQuery(),this.isMounted&&this.startQuerySubscription(),this.getExecuteSsrResult()||this.getExecuteResult()},e.prototype.executeLazy=function(){return this.runLazy?[this.runLazyQuery,this.execute()]:[this.runLazyQuery,{loading:!1,networkStatus:u.c.ready,called:!1,data:void 0}]},e.prototype.fetchData=function(){var t=this.getOptions();if(t.skip||!1===t.ssr)return!1;var e=this.currentObservable.query;return!!e.getCurrentResult().loading&&e.result()},e.prototype.afterExecute=function(t){var e=this,r=(void 0===t?{}:t).lazy,i=void 0!==r&&r;return this.isMounted=!0,i&&!this.runLazy||(this.handleErrorOrCompleted(),setTimeout((function(){e.currentObservable.query&&e.currentObservable.query.resetQueryStoreErrors()}))),this.previousOptions=this.getOptions(),this.unmount.bind(this)},e.prototype.cleanup=function(){this.removeQuerySubscription(),delete this.currentObservable.query,delete this.previousData.result},e.prototype.getOptions=function(){var e=t.prototype.getOptions.call(this);return this.lazyOptions&&(e.variables=Object(s.a)(Object(s.a)({},e.variables),this.lazyOptions.variables),e.context=Object(s.a)(Object(s.a)({},e.context),this.lazyOptions.context)),this.runLazy&&delete e.skip,e},e.prototype.getExecuteSsrResult=function(){var t,e=this.context&&this.context.renderPromises,r=!1===this.getOptions().ssr,i=this.refreshClient().client.disableNetworkFetches,s={loading:!0,networkStatus:u.c.loading,called:!0,data:void 0};return r&&(e||i)?s:(e&&(t=this.context.renderPromises.addQueryPromise(this,this.getExecuteResult)||s),t)},e.prototype.prepareObservableQueryOptions=function(){var t=this.getOptions();this.verifyDocumentType(t.query,i.c.Query);var e=t.displayName||"Query";return this.context&&this.context.renderPromises&&("network-only"===t.fetchPolicy||"cache-and-network"===t.fetchPolicy)&&(t.fetchPolicy="cache-first"),Object(s.a)(Object(s.a)({},t),{displayName:e,context:t.context,metadata:{reactComponent:{displayName:e}}})},e.prototype.initializeObservableQuery=function(){if(this.context&&this.context.renderPromises&&(this.currentObservable.query=this.context.renderPromises.getSSRObservable(this.getOptions())),!this.currentObservable.query){var t=this.prepareObservableQueryOptions();this.previousData.observableQueryOptions=Object(s.a)(Object(s.a)({},t),{children:null}),this.currentObservable.query=this.refreshClient().client.watchQuery(Object(s.a)({},t)),this.context&&this.context.renderPromises&&this.context.renderPromises.registerSSRObservable(this.currentObservable.query,t)}},e.prototype.updateObservableQuery=function(){if(this.currentObservable.query){var t=Object(s.a)(Object(s.a)({},this.prepareObservableQueryOptions()),{children:null});Object(a.a)(t,this.previousData.observableQueryOptions)||(this.previousData.observableQueryOptions=t,this.currentObservable.query.setOptions(t).catch((function(){})))}else this.initializeObservableQuery()},e.prototype.startQuerySubscription=function(){var t=this;if(!this.currentObservable.subscription&&!this.getOptions().skip){var e=this.currentObservable.query;this.currentObservable.subscription=e.subscribe({next:function(e){var r=e.loading,i=e.networkStatus,s=e.data,n=t.previousData.result;n&&n.loading===r&&n.networkStatus===i&&Object(a.a)(n.data,s)||t.forceUpdate()},error:function(e){if(t.resubscribeToQuery(),!e.hasOwnProperty("graphQLErrors"))throw e;var r=t.previousData.result;(r&&r.loading||!Object(a.a)(e,t.previousData.error))&&(t.previousData.error=e,t.forceUpdate())}})}},e.prototype.resubscribeToQuery=function(){this.removeQuerySubscription();var t=this.currentObservable.query.getLastError(),e=this.currentObservable.query.getLastResult();this.currentObservable.query.resetLastResults(),this.startQuerySubscription(),Object.assign(this.currentObservable.query,{lastError:t,lastResult:e})},e.prototype.getQueryResult=function(){var t=this.observableQueryFields(),e=this.getOptions();if(e.skip)t=Object(s.a)(Object(s.a)({},t),{data:void 0,error:void 0,loading:!1,called:!0});else{var r=this.currentObservable.query.getCurrentResult(),i=r.loading,n=r.partial,o=r.networkStatus,a=r.errors,c=r.error,p=r.data;if(a&&a.length>0&&(c=new u.b({graphQLErrors:a})),t=Object(s.a)(Object(s.a)({},t),{loading:i,networkStatus:o,error:c,called:!0}),i){var l=this.previousData.result&&this.previousData.result.data;t.data=l&&p?Object(s.a)(Object(s.a)({},l),p):l||p}else if(c)Object.assign(t,{data:(this.currentObservable.query.getLastResult()||{}).data});else{var b=this.currentObservable.query.options.fetchPolicy;if(e.partialRefetch&&!p&&n&&"cache-only"!==b)return Object.assign(t,{loading:!0,networkStatus:u.c.loading}),t.refetch(),t;t.data=p}}return t.client=this.client,this.previousData.loading=this.previousData.result&&this.previousData.result.loading||!1,this.previousData.result=t,t},e.prototype.handleErrorOrCompleted=function(){var t=this.currentObservable.query;if(t){var e=t.getCurrentResult(),r=e.data,i=e.loading,s=e.error;if(!i){var n=this.getOptions(),o=n.query,u=n.variables,c=n.onCompleted,p=n.onError;if(this.previousOptions&&!this.previousData.loading&&Object(a.a)(this.previousOptions.query,o)&&Object(a.a)(this.previousOptions.variables,u))return;c&&!s?c(r):p&&s&&p(s)}}},e.prototype.removeQuerySubscription=function(){this.currentObservable.subscription&&(this.currentObservable.subscription.unsubscribe(),delete this.currentObservable.subscription)},e.prototype.observableQueryFields=function(){return{variables:this.currentObservable.query.variables,refetch:this.obsRefetch,fetchMore:this.obsFetchMore,updateQuery:this.obsUpdateQuery,startPolling:this.obsStartPolling,stopPolling:this.obsStopPolling,subscribeToMore:this.obsSubscribeToMore}},e}(p);function b(t,e,r){void 0===r&&(r=!1);var o=Object(n.useContext)(Object(i.d)()),u=Object(n.useReducer)((function(t){return t+1}),0),c=u[0],p=u[1],b=e?Object(s.a)(Object(s.a)({},e),{query:t}):{query:t},h=Object(n.useRef)();h.current||(h.current=new l({options:b,context:o,forceUpdate:p}));var v=h.current;v.setOptions(b),v.context=o;var O=function(t,e){var r=Object(n.useRef)();return r.current&&Object(a.a)(e,r.current.key)||(r.current={key:e,value:t()}),r.current.value}((function(){return r?v.executeLazy():v.execute()}),{options:Object(s.a)(Object(s.a)({},b),{onError:void 0,onCompleted:void 0}),context:o,tick:c}),d=r?O[1]:O;return Object(n.useEffect)((function(){return v.afterExecute({lazy:r})}),[d.loading,d.networkStatus,d.error,d.data]),Object(n.useEffect)((function(){return function(){return v.cleanup()}}),[]),O}function h(t,e){return b(t,e,!1)}function v(t,e){return b(t,e,!0)}var O=function(t){function e(e){var r=e.options,s=e.context,n=e.result,o=e.setResult,u=t.call(this,r,s)||this;return u.runMutation=function(t){void 0===t&&(t={}),u.onMutationStart();var e=u.generateNewMutationId();return u.mutate(t).then((function(t){return u.onMutationCompleted(t,e),t})).catch((function(t){if(u.onMutationError(t,e),!u.getOptions().onError)throw t}))},u.verifyDocumentType(r.mutation,i.c.Mutation),u.result=n,u.setResult=o,u.mostRecentMutationId=0,u}return Object(s.c)(e,t),e.prototype.execute=function(t){return this.isMounted=!0,this.verifyDocumentType(this.getOptions().mutation,i.c.Mutation),t.client=this.refreshClient().client,[this.runMutation,t]},e.prototype.afterExecute=function(){return this.isMounted=!0,this.unmount.bind(this)},e.prototype.cleanup=function(){},e.prototype.mutate=function(t){var e=this.getOptions(),r=e.mutation,i=e.variables,n=e.optimisticResponse,o=e.update,u=e.context,a=void 0===u?{}:u,c=e.awaitRefetchQueries,p=void 0!==c&&c,l=e.fetchPolicy,b=Object(s.a)({},t),h=Object.assign({},i,b.variables);return delete b.variables,this.refreshClient().client.mutate(Object(s.a)({mutation:r,optimisticResponse:n,refetchQueries:b.refetchQueries||this.getOptions().refetchQueries,awaitRefetchQueries:p,update:o,context:a,fetchPolicy:l,variables:h},b))},e.prototype.onMutationStart=function(){this.result.loading||this.getOptions().ignoreResults||this.updateResult({loading:!0,error:void 0,data:void 0,called:!0})},e.prototype.onMutationCompleted=function(t,e){var r=this.getOptions(),i=r.onCompleted,s=r.ignoreResults,n=t.data,o=t.errors,a=o&&o.length>0?new u.b({graphQLErrors:o}):void 0;this.isMostRecentMutation(e)&&!s&&this.updateResult({called:!0,loading:!1,data:n,error:a}),i&&i(n)},e.prototype.onMutationError=function(t,e){var r=this.getOptions().onError;this.isMostRecentMutation(e)&&this.updateResult({loading:!1,error:t,data:void 0,called:!0}),r&&r(t)},e.prototype.generateNewMutationId=function(){return++this.mostRecentMutationId},e.prototype.isMostRecentMutation=function(t){return this.mostRecentMutationId===t},e.prototype.updateResult=function(t){!this.isMounted||this.previousResult&&Object(a.a)(this.previousResult,t)||(this.setResult(t),this.previousResult=t)},e}(p);function d(t,e){var r=Object(n.useContext)(Object(i.d)()),o=Object(n.useState)({called:!1,loading:!1}),u=o[0],a=o[1],c=e?Object(s.a)(Object(s.a)({},e),{mutation:t}):{mutation:t},p=Object(n.useRef)();var l=(p.current||(p.current=new O({options:c,context:r,result:u,setResult:a})),p.current);return l.setOptions(c),l.context=r,Object(n.useEffect)((function(){return l.afterExecute()})),l.execute(u)}var f=function(t){function e(e){var r=e.options,i=e.context,s=e.setResult,n=t.call(this,r,i)||this;return n.currentObservable={},n.setResult=s,n.initialize(r),n}return Object(s.c)(e,t),e.prototype.execute=function(t){if(!0===this.getOptions().skip)return this.cleanup(),{loading:!1,error:void 0,data:void 0,variables:this.getOptions().variables};var e=t;this.refreshClient().isNew&&(e=this.getLoadingResult());var r=this.getOptions().shouldResubscribe;return"function"===typeof r&&(r=!!r(this.getOptions())),!1!==r&&this.previousOptions&&Object.keys(this.previousOptions).length>0&&(this.previousOptions.subscription!==this.getOptions().subscription||!Object(a.a)(this.previousOptions.variables,this.getOptions().variables)||this.previousOptions.skip!==this.getOptions().skip)&&(this.cleanup(),e=this.getLoadingResult()),this.initialize(this.getOptions()),this.startSubscription(),this.previousOptions=this.getOptions(),Object(s.a)(Object(s.a)({},e),{variables:this.getOptions().variables})},e.prototype.afterExecute=function(){this.isMounted=!0},e.prototype.cleanup=function(){this.endSubscription(),delete this.currentObservable.query},e.prototype.initialize=function(t){this.currentObservable.query||!0===this.getOptions().skip||(this.currentObservable.query=this.refreshClient().client.subscribe({query:t.subscription,variables:t.variables,fetchPolicy:t.fetchPolicy}))},e.prototype.startSubscription=function(){this.currentObservable.subscription||(this.currentObservable.subscription=this.currentObservable.query.subscribe({next:this.updateCurrentData.bind(this),error:this.updateError.bind(this),complete:this.completeSubscription.bind(this)}))},e.prototype.getLoadingResult=function(){return{loading:!0,error:void 0,data:void 0}},e.prototype.updateResult=function(t){this.isMounted&&this.setResult(t)},e.prototype.updateCurrentData=function(t){var e=this.getOptions().onSubscriptionData;this.updateResult({data:t.data,loading:!1,error:void 0}),e&&e({client:this.refreshClient().client,subscriptionData:t})},e.prototype.updateError=function(t){this.updateResult({error:t,loading:!1})},e.prototype.completeSubscription=function(){var t=this.getOptions().onSubscriptionComplete;t&&t(),this.endSubscription()},e.prototype.endSubscription=function(){this.currentObservable.subscription&&(this.currentObservable.subscription.unsubscribe(),delete this.currentObservable.subscription)},e}(p);function y(t,e){var r=Object(n.useContext)(Object(i.d)()),o=e?Object(s.a)(Object(s.a)({},e),{subscription:t}):{subscription:t},u=Object(n.useState)({loading:!o.skip,error:void 0,data:void 0}),a=u[0],c=u[1],p=Object(n.useRef)();var l=(p.current||(p.current=new f({options:o,context:r,setResult:c})),p.current);return l.setOptions(o,!0),l.context=r,Object(n.useEffect)((function(){return l.afterExecute()})),Object(n.useEffect)((function(){return l.cleanup.bind(l)}),[]),l.execute(a)}function g(){var t=o.a.useContext(Object(i.d)()).client;return Object(c.b)(t,1),t}var j=function(){function t(){this.queryPromises=new Map,this.queryInfoTrie=new Map}return t.prototype.registerSSRObservable=function(t,e){this.lookupQueryInfo(e).observable=t},t.prototype.getSSRObservable=function(t){return this.lookupQueryInfo(t).observable},t.prototype.addQueryPromise=function(t,e){return this.lookupQueryInfo(t.getOptions()).seen?e():(this.queryPromises.set(t.getOptions(),new Promise((function(e){e(t.fetchData())}))),null)},t.prototype.hasPromises=function(){return this.queryPromises.size>0},t.prototype.consumeAndAwaitPromises=function(){var t=this,e=[];return this.queryPromises.forEach((function(r,i){t.lookupQueryInfo(i).seen=!0,e.push(r)})),this.queryPromises.clear(),Promise.all(e)},t.prototype.lookupQueryInfo=function(t){var e=this.queryInfoTrie,r=t.query,i=t.variables,s=e.get(r)||new Map;e.has(r)||e.set(r,s);var n=JSON.stringify(i),o=s.get(n)||{seen:!1,observable:null};return s.has(n)||s.set(n,o),o},t}()}}]);
//# sourceMappingURL=5fe2f30b3c148a2bf3eab639de66a2b1527830fb.04674810f05dfafe96b0.js.map